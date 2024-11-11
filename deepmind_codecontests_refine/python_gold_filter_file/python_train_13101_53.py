N,C,K,*T=map(int,open(0).read().split());T.sort();B=M=L=0
for t in T:
 M+=1
 if M>C or t>L:B+=1;M=1;L=t+K
print(B)