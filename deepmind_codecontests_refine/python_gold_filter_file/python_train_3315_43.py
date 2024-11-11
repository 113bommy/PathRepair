A,B=map(int,input().split(" "))
print("Impossible" if A*B*(A+B)%3 else "Possible")