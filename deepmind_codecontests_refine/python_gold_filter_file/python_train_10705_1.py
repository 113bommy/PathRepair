N=input()
t=sum(map(int, list(N)))
print("No" if int(N)%t else "Yes")