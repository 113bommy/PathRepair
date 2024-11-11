A=[int(input()) for _ in range(5)]
K=int(input())
print("Yay!" if max(A)-min(A)<=K else ":(")