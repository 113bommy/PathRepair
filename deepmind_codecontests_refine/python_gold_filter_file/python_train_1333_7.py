A=[int(input())for _ in[0]*5]
B=[-(-a//10)*10-a for a in A]
print(sum(B)+sum(A)-max(B))
