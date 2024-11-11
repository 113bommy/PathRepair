fedor = input()
matroskin = input()
sharik = input()
if fedor == "rock" and matroskin == "scissors" and sharik == "scissors":
    print("F")
elif fedor == "scissors" and matroskin == "paper" and sharik == "paper":
    print("F")
elif fedor == "paper" and matroskin == "rock" and sharik == "rock":
    print("F")
elif fedor == "paper" and matroskin == "scissors" and sharik == "paper":
    print("M")
elif fedor == "scissors" and matroskin == "rock" and sharik == "scissors":
    print("M")
elif fedor == "rock" and matroskin == "paper" and sharik == "rock":
    print("M")
elif fedor == "rock" and matroskin == "rock" and sharik == "paper":
    print("S")
elif fedor == "scissors" and matroskin == "scissors" and sharik == "rock":
    print("S")
elif fedor == "paper" and matroskin == "paper" and sharik == "scissors":
    print("S")
else:
    print("?")