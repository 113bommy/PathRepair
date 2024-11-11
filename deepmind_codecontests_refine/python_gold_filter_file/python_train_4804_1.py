k,m=int(input()),1500;a=m-k%m
print(m+1,'\n',*[0]*(m-1)+[-a,(k+a)//m+a])