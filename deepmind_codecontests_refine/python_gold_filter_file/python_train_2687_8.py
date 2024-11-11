import re
S = str(input())
acgt = re.compile(r"[A,C,G,T]*")
s = re.findall(acgt, S)
print(max(map(len,s)))