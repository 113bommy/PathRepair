A,B,C = map(int,input().split())

C = min(C, A+B+1)
answer = B+C
print(answer)