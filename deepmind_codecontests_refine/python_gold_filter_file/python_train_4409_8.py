n, m = [int(i) for i in input().split()]
for i in range(n):
    S = input()
    if(S.count('*')==2):
        S1 = S.find('*')
        S2 = S[S1+1:].find('*') + len(S[:S1]) + 1
    if(S.count('*')==1):
        S3 = S.find('*')
        l = i
if(S1==S3):
    print(l+1, S2+1)
else:
    print(l+1, S1+1)