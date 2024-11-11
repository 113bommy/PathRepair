N = input()

print("bon" if N[-1] == "3" else "pon" if N[-1] in "0168" else "hon")