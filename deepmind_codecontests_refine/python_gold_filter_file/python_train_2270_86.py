n,k=map(int,input().split())
s=str(input())
print(s[0:k-1]+s[k-1].lower()+s[k:n])