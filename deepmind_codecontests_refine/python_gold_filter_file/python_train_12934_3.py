from sys import stdin, stdout
import math
def divisor(n):
    i=1
    l=[]
    l.append(i)
    while i<=math.sqrt(n):
        if n%i==0:
            if i==n/i:
                l.append(i)
            else:
                l.append(i)
                l.append(n//i)
        i+=1
    l.sort()    
    return l    
def solve(d,k,c,n):
    kmin=n
    for i in range(k):
        st=len(d[i]) 
        if kmin>st:
            kmin=st
        l=divisor(st)
        #print(d[i],l)
        for i1 in l:
            length=st//i1
            j=-1
            for i2 in range(i1):
                j+=1
                ind=j
                cnt=length-1
                ch=1
                while cnt:
                    if c[d[i][ind]]!=c[d[i][(ind+i1)%st]]:
                        ch=0
                        break
                    ind=(ind+i1)%st
                    cnt-=1
                if ch==1:
                    if kmin>i1:
                        kmin=i1
                    break
            if kmin<=i1:
                break
    return kmin    

            
def main():
    t=int(input())
    while t:
        #n,k=map(int,input().split())
        n=int(input())
        #x=input()
        l=list(map(int,input().split()))
        c=list(map(int,input().split()))
        l.insert(0,0)
        c.insert(0,0)
        presnt={}
        parent={}
        d={}
        for i in range(1,n+1):
            presnt[i]=1
            parent[l[i]]=i
        l=n
        k=0
        while l>0:
            if d.get(k,-1)==-1:
                d[k]=[]
            for i in presnt:
                j=i
                break
            j1=parent[j]
            del presnt[j]
            d[k].append(j1)
            l-=1
            while j!=j1:
                del presnt[j1]
                j1=parent[j1]
                d[k].append(j1)
                l-=1
            #print(k,presnt)
            k+=1
        #print(d)    
        kmin=solve(d,k,c,n)
        print(kmin)
        t-=1    
if __name__ == "__main__": 
    main()          