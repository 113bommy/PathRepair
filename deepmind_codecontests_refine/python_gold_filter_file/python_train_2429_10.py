import math
st=''


def func(n,s):
    s1,s2=sorted(s[:n]),sorted(s[n:])
    if s1[0]<s2[0]:
        for i in range(n):
            if s1[i]>=s2[i]:
                return 'NO'
        return 'YES'
    elif s1[0]>s2[0]:
        for i in range(n):
            if s1[i]<=s2[i]:
                return 'NO'
        return 'YES'
    else:
        return 'NO'




for _ in range(1):#int(input())):
    #n,k=map(int,input().split())
    n = int(input())
    #l1=[]
    #inp=input().split()
    s=input()
    #l1=list(map(int,input().split()))
    #l2 = list(map(int, input().split()))
    #l1=input().split()
    #l2=input().split()
    st+=str(func(n,s))+'\n'

print(st)