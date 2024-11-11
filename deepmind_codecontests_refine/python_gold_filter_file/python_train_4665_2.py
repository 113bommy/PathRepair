n = int(input())
q= sorted(list(map(int,input().split())))
print(q[n//2]-q[n//2-1])
