
#n=int(input())
'''
a=i=0
l=[]
for i in range(n):
    l.append(int(input()))
    a=l[i]//2
    if l[i]==0 or l[i]==1 or l[i]==2:
        print(0)
    elif l[i]==3:
        print(1)
    elif a%2==0:
        print(a-1)
    else:
        print(a)
        '''
'''
l=[]
count=a=b=0
for i in range(n):
    l.append(int(input()))
    while(l[i]>0):
        a=1
        b=n-a
        count+=1
        a+=1
        b-=1
        if b>=a:
            break
        else:
            print(count)
    print(count)
'''

n=int(input())
a=i=0
l=[]
for i in range(n):
    l.append(int(input()))
    if l[i]==0 or l[i]==1 or l[i]==2:
        print(0)
    elif l[i]%2!=0:
        print(l[i]//2)
    elif l[i]%2==0:
        print((l[i]//2)-1)