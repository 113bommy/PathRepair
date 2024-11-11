import sys

def answer(n, x, u, v):
    adj_list = [[] for _ in range(n+1)] #first [] will never be filled.
    visited = [False for _ in range(n+1)] #[0] will never change.
    for i in range(n-1):
        adj_list[u[i]].append(v[i])
        adj_list[v[i]].append(u[i])
    if len(adj_list[x]) <= 1:
        return 'Ayush'
    if n % 2 == 0:
        return 'Ayush'
    return 'Ashish'

def main():
    t = int(sys.stdin.readline())
    while t:
        n, x = map(int, sys.stdin.readline().split())
        u = [0 for _ in range(n-1)]
        v = [0 for _ in range(n-1)]
        for i in range(n-1):
            u[i], v[i] = map(int, sys.stdin.readline().split())
        print(answer(n, x, u, v))
        t -= 1
    return
main()