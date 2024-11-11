n=int(input())
p=0
for i in range(n):
    k=input()
    if k=="1 1 1" or k=="1 1 0" or k=='1 0 1' or k=='0 1 1':
        p=p+1
print(p)

