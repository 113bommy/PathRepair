class GameOfRobots:
	def __init__(self, n, k, identifiers):
		self.n = n
		self.k = k
		self.identifiers = identifiers

	def playTheGame(self):
		i = 1
		temp = 0
		while True:
			s = self.totalSum(i)
			if s >= self.k:
				break
			else:
				temp = s
				i += 1
		print(self.identifiers[self.k-temp-1])

	def totalSum(self, i):
		return int(i*(i+1)/2)

if __name__=="__main__":
	n, k = [int(i) for i in input().split()]
	identifiers = [int(i) for i in input().split()]
	gameOfRobots = GameOfRobots(n, k, identifiers)
	gameOfRobots.playTheGame()