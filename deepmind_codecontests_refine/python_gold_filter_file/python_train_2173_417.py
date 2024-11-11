N,L=map(int, input().split())
print("".join(sorted([input()[:L] for i in range(N)])))
