n=input()
k=n.count('1')
n=n.replace('1','')+'2'
ind=n.find('2')
print(n[:ind]+'1'*k+n[ind:-1])
