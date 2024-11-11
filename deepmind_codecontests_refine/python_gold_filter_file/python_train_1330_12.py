s=input()
if s[-1] in "24579":
	print("hon")
else:print("pon" if s[-1] in "0168" else "bon")
