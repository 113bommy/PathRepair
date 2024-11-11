n,a,b=map(int,input().split())
print(n//(a+b)*a + min(a,(n-n//(a+b)*(a+b))))