import bisect
n=int(input())
a=list(map(int,input().split(' ')))

summ_l=[0]*n
l=[0]*n
left_book_numbers=[0]*n
left_book_indices=[0]*n

summ_l[0]=a[0]
l[0]=a[0]
left_book_numbers[0]=a[0]
left_book_indices[0]=0
p=1


# print(left_book_numbers)
for i in range(1,n):
	if(a[i]<=left_book_numbers[0]):
		# print('here1:',i)
		left_book_numbers[0]=a[i]
		left_book_indices[0]=i
		p=1
		summ_l[i]=(i+1)*(a[i])
	elif(left_book_numbers[p-1]<a[i]):
		# print('here2:',i)
		left_book_numbers[p]=a[i]
		left_book_indices[p]=i
		summ_l[i]=summ_l[i-1]+a[i]
		p+=1
	else:
		# print('here3',i)
		j=bisect.bisect_left(left_book_numbers,a[i],0,p)
		summ_l[i]=summ_l[left_book_indices[j-1]]+(i- left_book_indices[j-1] )*a[i]
		left_book_numbers[j]=a[i]
		left_book_indices[j]=i

		p=j+1
	# print(left_book_numbers,'pointer:',p)

# print(summ_l)

a.reverse()

summ_r=[0]*n
l=[0]*n
left_book_numbers=[0]*n
left_book_indices=[0]*n

summ_r[0]=a[0]
l[0]=a[0]
left_book_numbers[0]=a[0]
left_book_indices[0]=0
p=1


# print(left_book_numbers)
for i in range(1,n):
	if(a[i]<=left_book_numbers[0]):
		# print('here1:',i)
		left_book_numbers[0]=a[i]
		left_book_indices[0]=i
		p=1
		summ_r[i]=(i+1)*(a[i])
	elif(left_book_numbers[p-1]<a[i]):
		# print('here2:',i)
		left_book_numbers[p]=a[i]
		left_book_indices[p]=i
		summ_r[i]=summ_r[i-1]+a[i]
		p+=1
	else:
		# print('here3',i)
		j=bisect.bisect_left(left_book_numbers,a[i],0,p)
		summ_r[i]=summ_r[left_book_indices[j-1]]+(i- left_book_indices[j-1] )*a[i]
		left_book_numbers[j]=a[i]
		left_book_indices[j]=i

		p=j+1
	# print(left_book_numbers,'pointer:',p)
summ_r.reverse()
# print(summ_r)
a.reverse()

totals_list=[]
for i in range(n):
	totals_list.append(summ_l[i]-a[i]+summ_r[i])
# print(totals_list)	
mi=totals_list.index(max(totals_list))
# print(i)
result=[0]*n

result[mi]=a[mi]
i=mi-1
while i>=0:
	result[i]=min(result[i+1],a[i])
	i-=1
i=mi+1
while i<=n-1:
	result[i]=min(result[i-1],a[i])
	i+=1
for x in result:
	print(x,end=' ')
print()