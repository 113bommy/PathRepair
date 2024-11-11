def main():
	s=input()
	ans=''
	for i in s:
		if i in 'AOYEUIaoyeui':
			pass
		else:
			ans+='.'+ i.lower()
	print(ans)
	return 0

if __name__ == '__main__':
	main()
