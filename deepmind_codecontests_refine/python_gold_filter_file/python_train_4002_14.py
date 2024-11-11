upreg=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
downreg=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
cifra=['1','2','3','4','5','6','7','8','9','0']
slovo=input()
flag=[0,0,0,0]
if len(slovo)>=5:
    flag[0]=1
for i in range(len(slovo)):
    simvol=slovo[i:i+1]
    if simvol in upreg:
        flag[1]=1
    if simvol in downreg:
        flag[2]=1
    if simvol in cifra:
        flag[3]=1
if flag[0] and flag[1] and flag[2] and flag[3]:
    print('Correct')
else:
    print('Too weak')
