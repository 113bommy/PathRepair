import sys
def input(): return sys.stdin.readline().rstrip()

N = int(input())
A = list(map(int, input().split()))

A_max = max(A)
prime = [[] for _ in range(A_max + 1)]
for i in range(2,A_max + 1):
    if prime[i] == []:
        n = i
        while n <= A_max:
            prime[n].append(i)
            n += i

li = [0] * (A_max + 1)
for a in A:
    for p in prime[a]:
        li[p] += 1


if max(li) <= 1:
    print('pairwise coprime')
elif max(li) == N:
    print('not coprime')
else:
    print('setwise coprime')