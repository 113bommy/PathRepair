n,k = [int(i) for i in input().split(" ")]
p=1
while p>=1:
	# print((((n*p)-k)%10) ,(((n*(p)))%10==0))
	if (((n*p)-k)%10==0) or ((n*p)%10==0) :
		print(p)
		break;
	else:
		p+=1
# if p==10:
# 	print(0)