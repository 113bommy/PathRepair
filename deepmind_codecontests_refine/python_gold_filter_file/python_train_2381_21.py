while True:
	try:
		a,b,c,d,e,f = map(int, input().split())
		x = (c*d-a*f)/(b*d-a*e)
		print("{:.3f} {:.3f}".format((c-b*x)/a, x))
	except:
		break

