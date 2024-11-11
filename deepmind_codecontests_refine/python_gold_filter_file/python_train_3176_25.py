a,b = input().split()
saida = b + "0"*(int(a) - len(b))
if(a == "1" and b == "10"):
    print(-1)
else:
    print(int(saida))