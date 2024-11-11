n,p=map(int, input().split())
for i in range(1,33):
    x=n-i*p
    if x>=i and bin(x).count('1')<=i:
        print(i)
        exit(0)
print(-1)