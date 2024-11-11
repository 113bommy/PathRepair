N = int(input())
a = list(map(int, input().split()))
ma = a.index(max(a))+1
mi = a.index(min(a))+1
print(2*N-1)

if (abs(max(a)) >= abs(min(a))):
    for i in range(1, N+1):
        print(str(ma) + " " + str(i))
    for i in range(1, N):
        print(str(i) + " " + str(i+1))
else:
    for i in range(1, N+1):
        print(str(mi) + " " + str(i))
    for i in reversed(range(2, N+1)):
        print(str(i) + " " + str(i-1))