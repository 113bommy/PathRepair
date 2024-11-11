n,k=map(int,input().split())
s=input()
k-=1
print(s[:k]+s[k:k+1].lower()+s[k+1:])