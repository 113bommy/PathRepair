N=int(input())
s=input()
t=input()
for i in range(N):
    if s[i:]==t[:(N-i)]:
        print(N+i)
        exit()
print(N*2)