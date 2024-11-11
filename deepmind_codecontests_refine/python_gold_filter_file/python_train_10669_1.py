n=int(input())
l=list(map(int,input().split()))
b=sorted(l)
ans=[]
for x in l:
    ans.append(b[::-1].index(x)+1)
print(' '.join(map(str,ans)))