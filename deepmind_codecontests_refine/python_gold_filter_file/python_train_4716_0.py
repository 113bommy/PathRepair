from collections import deque


T = int(input())
r = 1
maxdigit = 20


def fastfrac(a,b,M):
    numb = pow(b,M-2,M)
    return ((a%M)*(numb%M))%M

def getnum(k,s):

   
    n = len(s)
    dic = {}

   
  
    prefixnum = max(0,k-maxdigit)
    real = k - prefixnum
    maxreal = (1<<real) - 1
    front = 0

    pres = deque()
    for i in range(prefixnum):
        if s[i]=='1': pres.append(i)

    
    num = int(s[prefixnum:prefixnum+real],2)
   

    if len(pres)==prefixnum:
        dic[maxreal-num] = 1
        if maxreal-num==front: front += 1
#    print(pres)        

    for i in range(n-k):
        if prefixnum>0:
            if pres and pres[0]==i: pres.popleft()
            if s[i+prefixnum] =='1': pres.append(i+prefixnum)
#        print(pres)


        num = num % ((maxreal+1)//2)
        num = 2*num + int(s[i+k])
  
        if len(pres)<prefixnum: continue
       
        dic[maxreal-num] = 1
        while front in dic:
            front += 1

#    print(dic)

    if front>maxreal: return -1
    else: return front
     
      
            

        
        
    
    



while r<=T:
    n,k = map(int,input().split())
    s = input()

    ans = getnum(k,s)

    if ans>=0:
        print("YES") 
        subs = bin(ans)[2:]
        subs = '0'*(k-len(subs)) + subs
        print(subs)
    else:
        print("NO") 


    r += 1
