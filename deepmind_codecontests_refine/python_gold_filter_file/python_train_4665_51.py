n=int(input())
ls=list(map(int,input().split()))
ls.sort()

print(ls[n//2]-ls[n//2-1])
