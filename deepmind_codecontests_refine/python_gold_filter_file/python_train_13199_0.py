n=int(input())
print(min(i+n//i-2 for i in range(1,int(n**.5)+1) if n%i<1))