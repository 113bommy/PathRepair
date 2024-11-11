n = int(input())
la = list(map(int, input().split()))*2
la.sort(reverse=True)
print(sum(la[1:n]))