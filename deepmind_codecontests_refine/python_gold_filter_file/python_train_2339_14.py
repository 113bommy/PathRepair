a = input()
b = input()
c = input()
k = 0
if a == "paper":
	if b == "rock" and c == "rock":
		k = 1
		print("F")
if a == "rock":
	if b == "scissors" and c == "scissors":
		k = 1
		print("F")
if a == "scissors":
	if b == "paper" and c == "paper":
		k = 1
		print("F")
elif  b == "paper":
	if c == "rock" and a == "rock":
		k = 1
		print("M")
if b == "rock":
	if a == "scissors" and c == "scissors":
		k = 1
		print("M")
if b == "scissors":
	if a == "paper" and c == "paper":
		k = 1
		print("M")
elif c == "paper":
	if b == "rock" and a == "rock":
		k = 1
		print("S")
if c == "rock":
	if b == "scissors" and a == "scissors":
		k = 1
		print("S")
if c == "scissors":
	if b == "paper" and a == "paper":
		k = 1
		print("S")
if k == 0:
	print("?")
