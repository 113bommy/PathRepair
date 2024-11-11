n=int(input())

h="that I hate"
l="that I love"
end="it"
s="I hate"
if n==1:
	print(s+" "+end)
elif n>1:
	for i in range(1,n):
		if(i%2==0):
			s=s+" "+h
		else:
			s=s+" "+l
	s=s+" "+end
	print(s)






