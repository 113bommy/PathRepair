x= int(input())
lucky = [i for i in range(x,x+20) if '8' in str(i) and i != x]
minDif = 100
for i in lucky:
    if abs(i - x) < minDif :
        minDif = abs(i-x)
print(minDif)
