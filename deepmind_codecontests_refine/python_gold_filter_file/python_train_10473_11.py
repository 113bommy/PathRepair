def Calc_Sum(x:int, y:int):
    return (x+1)*y*(y+1)//2 +\
           (y+1)*x*(x+1)//2

m, b= map(int, input().split())

answer=int(0)


for y in range(b,-1,-1):
    x= m*(b-y)
    answer= max(answer, Calc_Sum(x, y))

print(int(answer))