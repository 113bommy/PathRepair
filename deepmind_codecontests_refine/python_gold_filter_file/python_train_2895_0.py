S=input()
c=S[::2].count("0")+S[1::2].count("1")
print(min(c,len(S)-c))
