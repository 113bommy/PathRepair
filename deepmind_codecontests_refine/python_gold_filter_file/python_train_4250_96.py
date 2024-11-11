a,b,k = map(int,input().split())
wa = []
for i in range(1,101):
    if a%i == 0 and b%i == 0:
        wa.append(i)
print(wa[-k])