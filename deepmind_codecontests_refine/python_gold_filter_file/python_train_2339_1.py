#https://codeforces.com/problemset/problem/48/A
player_f = input()[0]
player_m = input()[0]
player_s = input()[0]

def winner(player,opp1,opp2):
  if player == "r":
    if opp1 == "s" and opp2 == "s":
      return "W"
  elif player == "p":
    if opp1 == "r" and opp2 == "r":
      return "W"
  else:
    if opp1 == "p" and opp2 == "p":
      return "W"

if winner(player_f,player_m,player_s) == "W":
  print ("F")
elif winner(player_m,player_f,player_s) == "W":
  print("M")
elif winner(player_s,player_f,player_m) == "W":
  print("S")
else:
  print ("?")
