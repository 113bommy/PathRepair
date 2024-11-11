S,A,B=map(int,input().split())
print((S//(A+B))*A+min(A,S%(A+B)))