n=int(input())
l=list(map(int,input().split()))
p=list(l)
for i in range(len(l)):
    p[l[i]-1]=i+1
print(' '.join(map(str,p)))