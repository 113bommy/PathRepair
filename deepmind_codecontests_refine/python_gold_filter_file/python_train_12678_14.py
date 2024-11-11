N,A,B = map(int,input().split(sep=" "))
print((N//(A+B)*A)+ min(N%(A+B),A))