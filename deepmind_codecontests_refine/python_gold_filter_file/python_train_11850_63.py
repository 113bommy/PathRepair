N,M=map(int,input().split())
a=1
for i in range(1,4*10000):
    if M%i:
        continue
    if M//i>=N and i>a:
        a=i
    if i>=N and M//i>a:
        a=M//i
print(a)