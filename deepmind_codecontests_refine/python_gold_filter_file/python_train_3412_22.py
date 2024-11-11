k=int(input())
k9=k*9
l=10
for n in range(1,k+5):
    if l*7%k9==7%k9:
        print(n)
        break
    l=l*10%k9
else:
    print(-1)