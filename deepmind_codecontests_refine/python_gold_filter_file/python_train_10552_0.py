
def cic(my_string):
	my_hash=set();
	max_v=-1<<256;
	for i in range(len(my_string)):
		empty=my_string[i]+''
		if empty in my_hash:
			max_v=max(max_v,len(empty))
		else:
			my_hash.add(empty)
		for j in range(i+1,len(my_string)):
			empty+=my_string[j]
			if empty not in my_hash:
				my_hash.add(empty)
			else:
				max_v=max(max_v,len(empty))
	return 0 if max_v<0 else max_v

def main():
	my_string=input()
	print(cic(my_string))



if __name__=='__main__':
	main()
