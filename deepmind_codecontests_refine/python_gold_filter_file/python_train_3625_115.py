S=input()
print('WAAC'[S[0]=='A' and S.count('C',2,-1)==1 and len(list(filter(lambda x: x.isupper(),list(S))))==2::2])