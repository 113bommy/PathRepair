n,p=map(int, input().split())
for i in range(1,33):
    k=n-i*p
    if k>=i and bin(abs(k)).count('1')<=i:
        print(i)
        exit(0)
print(-1)