n=int(input())
s=input()
som=0
for i in range(n):
    if int(s[i])%2==0:
        som+=i+1
print(som)