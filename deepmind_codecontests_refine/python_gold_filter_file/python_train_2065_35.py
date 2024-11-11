N = int(input())
A = list(map(int,input().split()))
k = 0

while all(i%2 == 0 for i in A):
    A = [i/2 for i in A]
    k += 1

print(k)