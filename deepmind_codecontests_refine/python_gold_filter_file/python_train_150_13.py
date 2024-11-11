I=input
R=range
n=int(I())
s=I()
print(['no','yes'][any(max(map(len,s[j::i+1].split('.')))>4for i in R(n//4)for j in R(i+1))])