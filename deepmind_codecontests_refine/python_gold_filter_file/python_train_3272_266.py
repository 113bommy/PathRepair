n = int(input())
ai = list(map(int,input().split()))
print(*list(sorted(ai,reverse=False)))