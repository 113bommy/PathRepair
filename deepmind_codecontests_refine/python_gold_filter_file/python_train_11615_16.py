
def main():
	
	formato = input()
	hora = input()
	
	if int(hora[3]) > 5:
		hora = hora[:3] + '0' + hora[4]
	
	if formato == '12':
		if int(hora[:2]) > 12 or hora[:2] == '00':
			if hora[1] != '0':
				hora = '0' + hora[1:]
			else:
				hora = '10' + hora[2:]
	if formato == '24':
		if int(hora[:2]) > 23:
			hora = '0' + hora[1:]

				
	print(hora)
	return 0

if __name__ == '__main__':
	main()

