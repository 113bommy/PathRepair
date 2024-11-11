n=int(input())
l=list(map(int,input().split()))
m=sum([(i+1)!=l[i] for i in range(n)])
print("YES" if m==0 or m==2 else "NO")