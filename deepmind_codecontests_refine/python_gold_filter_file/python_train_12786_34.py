N = int(input())
a = N//7
AA = [(N-7*i)%4 for i in range(a+1)]
if 0 in AA:
    print("Yes")
else:
    print("No")
